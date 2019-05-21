import tensorflow as tf

def main(inference_only = True):
    input = tf.placeholder(tf.float32, shape = [1,28,28,1], name = "input")
    #help(tf.nn.conv2d)
    conv = tf.layers.conv2d(input, filters = 32, kernel_size = [3,3],
                    use_bias = False ,name = "conv")
    output = tf.identity(conv, name = "output")
    if inference_only == False:
        label = tf.placeholder(tf.float32, shape = output.get_shape().to_list(),
                                        name = "label")
        loss = tf.reduce_mean(tf.square(output - label))
        optimizer = tf.train.GradientDescentOptimizer(learning_rate = 0.001)
        train_op = optimizer.minimize(loss, name = "trainer")
    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())
        with open('model.pb', 'w') as file:
            file.write(tf.get_default_graph().as_graph_def().SerializeToString())



if __name__ == "__main__":
    main(True)
