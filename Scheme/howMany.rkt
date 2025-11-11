#lang racket

(define howMany
  (lambda (fn L)
    (list 
    (length (filter fn L))
    (- (length L) (length (filter fn L)))
    )
    ))

(define evenList?
    (lambda (E)
      (equal? (modulo (length E) 2) 0)
    ))