#lang racket

;; write a function that takes a list of words and returns the word that occurs most often in that list

(define test '(hi hi hi hey hey ho hi hey))
(define emptyList '() )
(define simple '(hi) )
(define simple2 '(hi hi) )
(define simple3 '(hey hi hi) )

(define maxFrom
  (lambda (L)
    (cond ( (null? L)   '()                        )
          ( (= (length L) 1) (car L)               )
          ( (= (length L) 2)                       )
          ( #t          (maxFrom (cdr L) )         )
          )))


