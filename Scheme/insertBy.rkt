#lang racket

(define insertBy
  (lambda (C E S)
    (cond ( (null? S) (list (car E)) )
          ( (equal? (C E (car S)) #t)  (cons E (cdr S) )                )
          ( #t (insertBy C E (cdr S) ) )
          )))

(define insertBy
(lambda (C E S)
(cond ((null? S) (list E))
      ((C E (car S)) (cons E S))
      (#t (cons (car S) (insertBy C E (cdr S))))
)))