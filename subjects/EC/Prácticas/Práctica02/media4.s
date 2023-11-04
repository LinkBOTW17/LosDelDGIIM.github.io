.section .data

#ifndef TEST	// Test por defecto
#define TEST 20
#endif

	.macro 	linea
#if TEST==1
		.int 1,2,1,2
#elif TEST==2
		.int -1,-2,-1,-2
#elif TEST==3
		.int 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF
#elif TEST==4
		.int 0x80000000, 0x80000000, 0x80000000, 0x80000000
#elif TEST==5
		.int 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF
#elif TEST==6
		.int 2000000000, 2000000000, 2000000000, 2000000000
#elif TEST==7
		.int 3000000000, 3000000000, 3000000000, 3000000000
#elif TEST==8
		.int -2000000000, -2000000000, -2000000000, -2000000000
#elif TEST==9
		.int -3000000000, -3000000000, -3000000000, -3000000000
#elif TEST>=10 && TEST<=14
		.int 1,1,1,1
#elif TEST>=15 && TEST<=19
		.int -1,-1,-1,-1
#else
	.error 	"Definir TEST entre 1..19"
#endif
	.endm



	.macro 	linea0
#if TEST>=1 && TEST<=9
		linea
#elif TEST==10
		.int 0,2,1,1
#elif TEST==11
		.int 1,2,1,1
#elif TEST==12
		.int 8,2,1,1
#elif TEST==13
		.int 15,2,1,1
#elif TEST==14
		.int 16,2,1,1
#elif TEST==15
		.int 0,-2,-1,-1
#elif TEST==16
		.int -1,-2,-1,-1
#elif TEST==17
		.int -8,-2,-1,-1
#elif TEST==18
		.int -15,-2,-1,-1
#elif TEST==19
		.int -16,-2,-1,-1
		
#else
	.error 	"Definir TEST entre 1..19"
#endif
	.endm



lista: 	linea0
		.irpc i,123	# Repite la correspondiente linea 3 veces
			linea
		.endr


longlista: 	.int (.-lista)/4
media: 	.int 0
resto: 	.int 0


formato:.ascii	"media\t= %11d \t resto\t= %11d\n"
		.ascii	"\t= 0x %08x \t\t= 0x %08x\n"


.section .text
main: .global  main

	call trabajar	# subrutina de usuario
	call imprim_C	# printf()  de libC
	call acabar_C	# exit()    de libC
	ret

trabajar:
	movq	 $lista, %rdi
	movl  longlista, %esi
	push %rsi		# Guardamos el valor de %rsi (salva invocante)
	call suma		# == suma(&lista, longlista);
	pop %rsi		# Obtenemos el valor de %rsi
	idiv %esi
	mov	 %eax, media
	mov  %edx, resto
	ret

suma:
	xor  %r8, %r8 # acarreo
	xor  %r9, %r9 # resultado
	xor  %r10, %r10 # i=0
bucle:

	movl  (%rdi,%r10,4), %eax
	cltd 	# Extiende el signo a %edx:%eax
	addl   %eax, %r9d # resultado += lista[rdx]
	adcl   %edx, %r8d
	inc    %r10		 # i++
	cmp   %r10d,%esi		 # i<longlista
	jne   bucle

	movl %r9d, %eax
	movl %r8d, %edx

	ret

imprim_C:			# requiere libC

	mov   media,%ecx		# 4º. Media hex
	mov   resto,%r8d		# 5º. Resto hex
	mov   $formato, %rdi	# 1er
	mov   media,%esi		# 2º Media decimal
	mov   resto,%edx		# 3º Resto decimal
	
	call  printf
	ret

acabar_C:
	mov  media, %rdi			# requiere libC
	call exit		# ==  exit(resultado)
	ret
