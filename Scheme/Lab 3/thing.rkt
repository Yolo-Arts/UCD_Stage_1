#lang racket

(define thing
  (lambda (a b c d)
    (b(a c d) (b d c) )
    ))