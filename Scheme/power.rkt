#lang racket

(define power
  (lambda L
    (cond ( (null? L)  1)
          ( (equal? (length L) 1) (car L) )
          ( #t (expt (car L) (apply power (cdr L) )))
          )))
               
(define nums '( 4 3 2) )


