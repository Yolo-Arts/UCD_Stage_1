#lang racket


;(define qualify
;  (lambda (E L)
;    (cond ( (null? L) (list E))
;          ( (equal? (car L) E) (cons 'really L) ) 
;          ( #t (cons (car L) (qualify E (cdr L)) ))
;          )))

; fails: (I really want to pass and don't really want to fail)
; output: (I really want to pass and don't want to fail)


(define qualify
  (lambda (E L)
    (cond ( (null? L) '())
          ( (equal? (car L) E) (append (append '(really) (list(car L))) (qualify E (cdr L)) ) ) 
          ( #t (cons (car L) (qualify E (cdr L)) ))
          )))

(define test1 '(like) )
(define test2 '(I want to pass and don't want to fail))
; expected output
; (I really want to pass and don't really want to fail)
; (I really want to pass and don't want to fail to pass and don't really want to fail to fail want)
