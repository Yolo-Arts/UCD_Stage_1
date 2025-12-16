#lang racket

(define chainTest
  (lambda (fn fn2 N)
     (fn (fn2 N))
    ))






(define lastElement
  (lambda (L)
    (cond ( (equal? (length L) 1) (car L) )
          ( #t (lastElement (cdr L)) )
          )))

(define cT
  (lambda L
    (lastElement L)
    ))
(cT sqrt sqrt 625)





(define chain
  (lambda L
    (cond ( (equal? (length L) 1) (lastElement L)                           )
          (#t                  ((car L) (apply chain (cdr L))))
      )))
 