#lang racket

(define average
  (lambda L
    (cond ( (null? L) 0 )
          ( #t (+ (car L) (apply average (cdr L)) ))
          )))

(define power
  (lambda L
    (cond ( (null? L) 1)
          ( #t (expt (car L) (apply power (cdr L))) )
          )))


(define countEven
  (lambda (L)
    (cond ( (null? L) 0)
          ( (even? (car L)) (+ 1 (countEven (cdr L)) ) )
          ( #t  (countEven (cdr L)) )
          )))


(define rev
  (lambda (L) 
    (cond ( (null? L) '() )
          ( (null? (cdr L) ) (car L) )
          )))