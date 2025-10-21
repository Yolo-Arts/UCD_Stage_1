#lang racket

;; maxList: Takes in a list of numbers and returns the highest
;; (maxList '(6 2 1 87 9 1))

(define maxList
  (lambda (L)
    (cond ((equal? (length L) 0)                0   )
          ((equal? (length L) 1)            (car L) )
          ( (> (car L) (maxList (cdr L)) )  (car L) ) ;; if first item is larger than all the other items in the list
          ( #t                    (maxList (cdr L)) ) ;; sends rest of the list, to repeat the previous step.
)))
