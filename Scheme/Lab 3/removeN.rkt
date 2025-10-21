#lang racket

(define removeN
  (lambda (N L )
    (cond ( (= (length L) 1) L )
          ( (< (length L) N) '() ) 
          ( #t  (removeN (- N 1) (cdr L)) ) 
          )))