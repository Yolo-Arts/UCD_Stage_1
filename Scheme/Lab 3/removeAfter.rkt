#lang racket


(define removeAfter
  (lambda (E L)
    (cond ( (equal? (length L) ) L )
          ( (equal? E (car L) ) '())
          ( #t  (cons (car L) (removeAfter E (cdr L) ) ) )
          )))
