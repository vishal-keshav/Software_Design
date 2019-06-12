# Sample model generator

import tensorflow as tf
import numpy as np

with tf.Session() as sess:
    t1 = tf.constant(1., shape = [2,2], name='t1')
    t2 = tf.constant(2., shape = [2,2], name='t2')
    add_op = tf.add(t1, t2, name ='add')
    out = tf.identity(add_op, name = 'output')
    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())
        out_result = sess.run(out)
    print(out_result)

    tf.train.write_graph(sess.graph_def, 'models/', 'graph.pb', as_text=False)
