#lang racket

(define countdown
  (lambda (n)
    (cond ( (= n 1) '(1) )
          ( (> n 1) (cons n (countdown (- n 1))) )
          )))

(define countStep
  (lambda (n step)
    (cond ( (< n 1) '() )
          ( #t (cons n (countStep (- n step) step)  ) )
          )))

