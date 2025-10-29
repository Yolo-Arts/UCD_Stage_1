#lang racket

(define selectionSort
  (lambda (lessThan L)
    (cond ( (null? L)     L)
          ( (null? (cdr L)  L ))
          ( #t (cons (lowest lessThan L) (selectionSort lessThan (removeLowest lessThan L) ) ) )
          )))
          
            