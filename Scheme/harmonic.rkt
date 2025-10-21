#lang racket

(define harmonic
  (lambda (n)
    (cond ( (= n 1) 1                     )
          ( (> n 1) (+ (harmonic (- n 1) ) (/ 1 n)  )
          )
    )
  ))