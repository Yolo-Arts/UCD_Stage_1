#lang racket

(define sumOfF
  (lambda (n f)
    (cond ((= n 1) ((f 1)                    )
          ((> n 1) (+ (sumOfF (- n 1) (f n))))
          )
          )
    ))
  
          

(define add
  (lambda (x)
    (+ x 1)
    ))