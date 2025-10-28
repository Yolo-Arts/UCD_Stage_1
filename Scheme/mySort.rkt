#lang racket

(define mySort
  (lambda (C L)
    (cond ( (null? L) '())
          ( (C (car L) (car (mySort C (cdr L)))) (cons (car L) (mySort (cdr L) )) )
          ( #t (mySort C (cdr L)) )
          )))


(define insertBy
  (lambda (C E L-sorted)
    (cond
      ((null? L-sorted) (list E)) 
      ((C E (car L-sorted)) (cons E L-sorted)) 
      (#t (cons (car L-sorted) (insertBy C E (cdr L-sorted)))))))

(define mySort
  (lambda (C L)
    (cond
      ((null? L) '())
      
      (#t (insertBy C (car L) (mySort C (cdr L)))))))

