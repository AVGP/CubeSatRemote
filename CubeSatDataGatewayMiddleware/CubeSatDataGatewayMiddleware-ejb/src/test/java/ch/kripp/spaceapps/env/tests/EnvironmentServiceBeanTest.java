package ch.kripp.spaceapps.env.tests;

import ch.kripp.spaceapps.domain.env.EnvironmentInfo;
import ch.kripp.spaceapps.env.EnvironmentServiceBean;
import org.junit.*;

/**
 *
 * @author frank
 */
public class EnvironmentServiceBeanTest {
    
    public EnvironmentServiceBeanTest() {
    }

    @BeforeClass
    public static void setUpClass() throws Exception {
    }

    @AfterClass
    public static void tearDownClass() throws Exception {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }
    // TODO add test methods here.
    // The methods must be annotated with annotation @Test. For example:
    //
    // @Test
    // public void hello() {}
    
    @Test
    public void envIdTest()
    {
        EnvironmentServiceBean bean = new EnvironmentServiceBean();
        EnvironmentInfo result = bean.getEnvironmentIdentifier();
        Assert.assertNotNull(result.getEnvName());
    }
    
}
