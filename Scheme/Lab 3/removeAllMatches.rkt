#lang racket

(define removeAllMatches
  (lambda (Fn L)
    (cond ( (null? L) '())
          ( (list? (car L)) (cons  (removeAllMatches Fn (car L)) (removeAllMatches Fn (cdr L))  )                                      )
          ( (equal? (Fn (car L)) #t) (removeAllMatches Fn (cdr L )) )
          ( #t (cons (car L) (removeAllMatches Fn (cdr L )) ))
          )))



