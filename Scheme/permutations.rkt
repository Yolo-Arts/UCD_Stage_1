#lang racket

;; given a list of things L = ('a b c)
;; return a list of all permuations of those things
;; ((a b c) (a c b) (b a c) (b c a) (c a b) (c b a)

;; What's the simplest list L where I can give (perm L) immediately?
;; what if L is empty? (perms '()) = ( () )
;; THere is one way of arranging an empty lsit

;; What if L is not emtpy? Pretend L = '(a b c). Now we need to make the list smaller so lets look at (cdr L)
;; Thats going to be (cdr L) = (b c).
;; What should (perm (cdr L)) = (perm '(b c))
;; (perm '(b c)) = '( (b c) (c b))
;; How do I go from '( (b c) (c b))
;; To:
;; ((a b c) (a c b) (b a c) (b c a) (c a b) (c b a)
;; using the leftover a (car L) ?
