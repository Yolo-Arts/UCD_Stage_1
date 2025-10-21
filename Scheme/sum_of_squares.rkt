#lang racket

(define square
  (lambda (x)
    (* x x)
    )
  )



(define sum_of_squares
  (lambda (n)
    (cond ((= n 1) (square n) )
        ( (> n 1) (+ (sum_of_squares (- n 1)) (square n) )
        ))))