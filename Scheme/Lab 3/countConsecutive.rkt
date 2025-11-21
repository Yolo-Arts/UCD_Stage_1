#lang racket

; the code here will create a list of 1's
; each 1 is the number of times that a pair appears in the list
; this does not return the number of consecutives however, as i would want to apply + to the result of this func

(define countConsecutive
  (lambda (L)
    (apply + (countConsecutiveHelper L))
    ))

(define countConsecutiveHelper
  (lambda (L)
    (cond ( (null? L)                   '()                          )
          ( (null? (cdr L))              '()                                )
          ( (equal? (car L) (car(cdr L)) )    (cons 1 (countConsecutiveHelper (cdr L))) )
          ( #t                 (countConsecutiveHelper (cdr L))      )
          )))

(define tc '(a b a))

(apply + (countConsecutive tc))

(define testCase2 '(a a b b))

(countConsecutive testCase2)

(countConsecutive '(a b b c d d c c) )

