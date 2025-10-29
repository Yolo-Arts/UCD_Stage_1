#lang racket

(define ssqrt
  (lambda L
    (cond ( (null? L)             0 )
          ( #t    (+ (sqrt (car L) )   (apply ssqrt (cdr L) ) ) )
          )))