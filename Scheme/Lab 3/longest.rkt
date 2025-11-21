#lang racket

; base case should be '()
; if the first list contains one item, and the second list contains 2 items.

(define longest
  (lambda (L)
    (cond (      (null? L)          '()                               )
          (      (> (length (car L)) (length (cdr L)) )  (car L)             )
          (      #t                             (longest (cdr L))        )
          )))