#lang racket

;; Fibonacci sequence >:(

(define fibN
  (lambda (N)
    (cond ( (equal? N 0) 0 )
          ( (equal? N 1) 1 )
          ;; ( (= N 3) 0 1 1)
          ;; ( (= N 4) 0 1 1 2)
          ( #t  (+ (fibN (- N 1)) (fibN (- N 2)) )  )
          )))

(define vals
  (lambda (F n)
    (cond ( (equal? n 0) (cons (F 0) '() ) )
          ( #t           (cons (F n) (vals F (- n 1)) ) )
          )))