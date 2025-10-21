#lang racket

(define removeMatch
  (lambda (Fn L)
    (cond ( (null? L) '())
          ( (equal? (Fn (car L)) #t) (removeMatch Fn (cdr L )) )
          ( #t (cons (car L) (removeMatch Fn (cdr L )) ))
          )))



