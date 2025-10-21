#lang racket

(define last
  (lambda (L)
    (cond ( (= (length L) 1) (car L))
          ( (> (length L) 1) (last (cdr L ) ) )
          )))
          