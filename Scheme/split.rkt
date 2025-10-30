#lang racket

(define split
  (lambda (L)
    (cond ( (null? L)    '( () () )                                           )
          ( (null? (cdr L) )     (list L '() )                                )
          (  #t        (list (filter (lambda(x) (<= x (car L ))) L )        ) )
          )))