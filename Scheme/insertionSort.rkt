#lang racket


(define sort
  (lambda (lessThan L)
    (cond ( (null? L)       L )
          ( (null? (cdr L)) L )
          ( #t             (insert lessThan (car L) (sort lessThan (cdr L) ) ) )
          )))










