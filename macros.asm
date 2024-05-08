fopen macro filename,handle

lea dx,filename
mov ah,3dh
mov al, 00h
int 21h
mov handle,ax
.if carry?
mov ax,-1
.endif
endm

fread macro numbytes, datasize, databuffer, handle
    mov ah, 3fh          
    mov bx, handle       
    mov cx, numbytes     
    mul cx               
    mov cx, ax           
    mov dx, datasize     
    mul dx               
    mov cx, ax           
    lea dx, databuffer   
    int 21h             
endm

fclose macro handle

mov ah,3eh
mov bx,handle
int 21h
endm
