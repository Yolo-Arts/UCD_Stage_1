#lang racket

;; write a function G with the following definition:
;; G(0) = 0
;; G(1) = 0
;; G(2) = 1
;; G(n) = G(n - 1) + G(n - 2) - G(n - 3)

(define G
  (lambda (n)
    (cond ( (equal? n 0) 0)
          ( (equal? n 1) 0)
          ( (equal? n 2) 1)
          ( #t (- (+ (G (- n 1)) (G (- n 2)) ) (G (- n 3)) ) )
          )))

;; (vals F n) -> Takes a function F and gives me a list ( (F n) (F (- n 1)) ... (F 0) )
;; Basically the sequence

(define vals
  (lambda (F n)
    (cond ( (equal? n 0) (cons (F 0) '() ) )
          ( #t           (cons (F n) (vals F (- n 1)) ) )
          )))