#lang racket

(define orderAdded
  (lambda (A L)
    (cond ( (equal? (length L) 0)              '()          )
          ;;( (equal? (length L) 1) (if (equal? (car L) A) (length L) 0) )
          ;;( (equal? (length L) 2) (if (equal? A (car L)) (length L) (orderAdded (A (cdr L)) ) ))
          
          ( (equal? (car L) A) (cons (length L) (orderAdded A (cdr L) ) ))
          ( #t (orderAdded A (cdr L) ) )
          )))
          