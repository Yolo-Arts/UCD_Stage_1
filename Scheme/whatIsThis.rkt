#lang racket

(define addAnA
  (lambda (L)
    (cons 'a L)
    ))

(define duplicate
  (lambda (L)
    (cons (car L) L)
    ))

(define whatIsThis
  (lambda (L)
    (cond ( (even? L) (- L 1))
          ( #t (+ L 1))
)))

