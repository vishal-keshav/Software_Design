# Complex inference model generator

import tensorflow as tf
import numpy as np

with tf.Session() as sess:
    t1 = tf.constant(1., shape = [1,32,32,3], name='t1')
    f = tf.constant(2., shape = [3,3,3,8], name='f')
    conv_op = tf.nn.conv2d(input = t1, filter = f,strides = [1,1,1,1], padding = 'SAME', name ='conv')
    out = tf.identity(conv_op, name = 'output')
    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())
        out_result = sess.run(out)
    print(out_result)

    tf.train.write_graph(sess.graph_def, 'models/', 'graph.pb', as_text=False)
