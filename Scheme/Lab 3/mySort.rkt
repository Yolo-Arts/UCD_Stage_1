#lang racket


(define mySort
  (lambda (C L)
    (cond ( (null? L) '() )
          ( #t (insertBy C (car L) (mySort C (cdr L)) ))
          )))


(define insertBy
  (lambda (C E S)
    (cond ( (null? S) (list E) )
          ( (C E (car S)) (cons E S) )
          ( #t (cons (car S) (insertBy C E (cdr S) ) ))
          )))