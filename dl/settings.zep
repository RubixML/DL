namespace Dl;

/**
 * Settings
 *
 * @category    Machine Learning
 * @package     Rubix/DL
 * @author      Andrew DalPino
 */
class Settings
{
    /**
     * Test interface to TensorFlow.
     */
    public static function tfVersion() -> string
    {
        return tf_version();
    }
}
