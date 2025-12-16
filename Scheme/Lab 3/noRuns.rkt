#lang racket

(define noRuns
  (lambda (L)
    (cond ( (null? L) '())
          ( (null? (cdr L)) (list (car L)) ) 
          ( (equal? (car L) (car (cdr L)) )   (noRuns (cdr L))         ) 
          ( #t (cons (car L) (noRuns (cdr L)) ))
          )))