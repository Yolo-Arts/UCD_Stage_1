#lang racket

;; (sum_sqrt '(1 2 3 4 5) )

(define sum_sqrt
  (lambda (x)
    (cond ( (empty? x ) 0)
          ( (not (empty? x)) (+ (sqrt (car x)) (sum_sqrt (cdr  x) ) ) )
          )
    )
  )