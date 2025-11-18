#lang racket

(define pickOne
  (lambda L
    (getElement (+ (random (length L)) 1) L)
    )
  )

(define getElement
  (lambda (N L)
    (cond ( (null? L) 0 )
          ( (= N 1) (car L) )
          ( (= N 2) (car (cdr L) ) )
          ( (= N 3) (car (cdr (cdr L) ) ) )
          ( #t (getElement (- N 1) (cdr L) ))
          )))