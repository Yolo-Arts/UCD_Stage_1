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