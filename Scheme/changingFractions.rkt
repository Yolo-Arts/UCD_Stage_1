#lang racket

(define changingFractions
  (lambda (X Y)
    (cond ( (= X 1) (/ X Y) )
          ( (= Y 1) (/ X Y) )
          ;; ( (#t) (+ (/ X Y) (/ (- X 1) (- Y 1) ) ) )
          ( #t (+ (changingFractions (- X 1)(- Y 1) ) (/ X Y) ) )
          )))
          