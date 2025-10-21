#lang racket

(define reciprocals
  (lambda (n)
    (cond ( (= n 1) 1 )
         
          ( (> n 1) (+ (/ 1 n) (reciprocals (- n 1) ) ) )
          )))