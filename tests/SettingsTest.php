<?php

namespace Tensor\Tests;

use DL\Settings;
use PHPUnit\Framework\TestCase;

/**
 * @covers \DL\Settings
 */
class SettingsTest extends TestCase
{
    /**
     * @test
     */
    public function tfVersion() : void
    {
        $this->assertIsString(Settings::tfVersion());
    }
}
