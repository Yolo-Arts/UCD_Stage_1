#lang racket

;; Read a list of people's ages and want to count how many are over 18

(define overAge
  (lambda (x age)
    (cond ((> x age) 1)
          ( #t 0)

    )))

(define bouncer
  (lambda (L age)
    (cond ( (= (length L) 0) 0 )
          ( #t (+ (overAge (car L) age) (bouncer (cdr L) age) )
          ))) )

          