	AREA FindZ, CODE, READONLY
	ENTRY
	
	ADR r7, VALA
	ADR r8, VALB
	ADR r9, VALC
	ADR r10, VALD
	ADR r11, VALE
		
	LDR r0, [r7]
	LDR r1, [r8]
	LDR r2, [r9]
	LDR r3, [r10]
	LDR r4, [r11]
	
	MUL r6, r3, r4
	ADD r0, r0, r1
	ADD r0, r0, r2
	SUB r0, r0, r6
	
	MOV r5, r0
	
	AREA FindZ, DATA, READWRITE
VALA	DCD 4
VALB	DCD 12
VALC	DCD -2
VALD	DCD 1
VALE	DCD 1
	
	END