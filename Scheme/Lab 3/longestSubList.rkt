#lang racket

;; here's a list of lists!

(define myLL '( (5 2) (6 7 8 9 a a a a) (hello I am a long list) ( a b c d e) ) )

;; write a function longestSubList that takes a list of lists and gives back the longest sublist in that list.

(define longestSubList
  (lambda (L)
    (cond ( (= (length L) 1)                                        (car L) )
          ( (> (length (car L)) (length(longestSubList (cdr L) ) )) (car L) )
          ( #t                                    (longestSubList (cdr L) ) )
          )))

    