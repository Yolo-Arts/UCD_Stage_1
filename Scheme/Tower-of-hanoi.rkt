#lang racket

; If I have 3 disks on TOWER A, and I want to move them to tower C:
; Can I do this recursively? What if I can move a smaller tower.
; moving a tower size 3 from A to C:
;           First move the top tower of size 2, From A to B.
;           and then move the bottom disk (the biggest one to C)
;           then move that smaller tower from B to C

; Lets think about what we're doing here?
; We want to have the same function to solve for n disks,
; and also use it to solve (Hanoi (n - 1)) for the smaller towers.
; So we need a function that can move n things from one tower to another
; (and we'll need to tell it which towers to move from and move to)

; so I realise that the function I want needs to take some arguments:
;    How many disks to move? What tower to take them from. What tower to put them on.

; Lets call this function "move" and it will look like this:

; (define move
;       (lambda (n start target helper)

; So with 3 disks on tower A and moving to tower C, the sequence I need is
; (move 2 'A 'B 'C) (move 1 'A 'C 'B) (move 2 'B 'C 'A)

; What if I had a different input?
; Suppose I had to move 3 disks from Tower C to tower B?
; (move 2 'C 'A 'B) (move 1 'C 'B 'A) (move 2 'A 'B 'C)

; Lets just replace the example names with their variable names.
; (move 3 start target helper) should give
; (move 2 start helper targer) (move 1 start target helper) (move 2 helper target start)

; so the general structure is something like this.
; (move n start target helper) should give
; (move (- n 1) start helper targer) (move 1 start target helper) (move (- n 1) helper target start)

; What about a base case?
; if n - 1, the all I need is (move n start target helper) => Actually move that disk somehow)

(define move
  (lambda (n start target helper)
    (cond ( (equal? n 1)          (list(list 'move 'one 'disk 'from start 'to target) )) 
          ( #t (append (move (- n 1) start helper target)
                       (append (move 1 start target helper)(move (- n 1) helper target start)) ))
    )))
               
                                  
















