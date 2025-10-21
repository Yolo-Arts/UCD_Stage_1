#lang racket

(define product
  (lambda (L)
    (cond ( (empty? L) 1)
          ( #t        (* (car L) (product (cdr L) ) ) )
          )))