#lang racket

;; write a function that takes a list L and returns a "concordance" that is a list
;; of pairs with each word is the list L occuring once, and inside it, the number of
;; times tjat "word" comes up to in the list L

(define hamlet '(to be or not to be that is the question) )
;; (concordance hamlet)
;; ( (to 2) (be 2) (or 1) (not 1) (that 1) (is 1) (the 1) (question 1) )

(define concordance
  (lambda (L)
    (cond ( (= (length L) 0) '()) 
          ( (= (length L) 1) (cons (car L) '(1)) )
          )))