#lang racket

;; function (sumTo L N) that gives me back a list of all combinations of numbers in L that add up to N
;;
;; What if the list is empty? The answer is a list with nothing in it '()
;;
;; Make a recursive call                (sumTo (cdr L) N) (sumTo (cdr L) (- N (car L)) )
;;
;; The leftover bit needs to be dealt with