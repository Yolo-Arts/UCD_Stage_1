#lang racket

(define aClosure
  (lambda (myName)

    (lambda (N)
      (list 'hi myName N 'squared 'is (* N N) )
      )
    )
  )

(define forMe (aClosure 'fintan) )

(define forYou (aClosure 'Jack) )

(forMe 7)
; '(hi fintan 7 squared is 49)

; closures carry around the scope. It remembers all the variables from the function it was called from.
; functions which hold state/context because they were created within the context and use the context.


; define a function addX that takes a number X and returns a FUNCTION that takes some other number and adds X to it.
;; (define myFun (addX 10))
;; Should give a function, and I call by saying (myFun 12) and get back (+ 10 12)

(define addX
  (lambda (X)

    (lambda (N)
      (+ X N)
    )
  )
  )

(define myFun (addX 10))
(myFun 12)


; A recurisve closure?
; Where the inner closure calls itself, even tho the inner function does not have a name.