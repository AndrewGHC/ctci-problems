; Remove duplicates from a linked list

(setq linked_list (cons 0 (cons 1 (cons 2 (cons 2 nil)))))

(loop for x in linked_list do (delete-duplicates linked_list))

(print linked_list)
