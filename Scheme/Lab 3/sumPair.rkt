#lang racket

;; given a list of numbers (call it L), write a function sumPairs that return a number equal to
;; the product of every side-by-side pair of numbers in L
;; so L = (5 1 2 4) -> 5*1 + 1*2 + 2*4 = 15

(define sumPair
  (lambda (L)
    (cond ( (= (length L) 1) 0 )              ;; Base case
          ( (> (length L) 1) ( +              ;; Adding the multiple of first two numbers with recursive case.
                               (*             ;; Multiplies first two numbers
                                (car L)
                                (car (cdr L)) ;; Gets second item of list
                                )
                               (sumPair (cdr L ) ) )
                             )
          )))
