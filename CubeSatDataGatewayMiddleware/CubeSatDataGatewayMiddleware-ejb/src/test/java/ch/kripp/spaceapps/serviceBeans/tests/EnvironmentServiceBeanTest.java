package ch.kripp.spaceapps.serviceBeans.tests;

import ch.kripp.spaceapps.ServiceModels.EnvironmentModel;
import ch.kripp.spaceapps.domain.Environment.EnvironmentInfo;
import ch.kripp.spaceapps.domain.entities.CfgEnvironmentDAO;
import ch.kripp.spaceapps.serviceBeans.EnvironmentServiceBean;
import org.easymock.EasyMock;
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

        EnvironmentModel emMock = EasyMock.createMock(EnvironmentModel.class);

        CfgEnvironmentDAO resultMock = new CfgEnvironmentDAO();
        resultMock.setIdentifier("DEV");
        resultMock.setMiddleware_version("0.0 UNITTEST");


        EasyMock.expect(emMock.querySingleCfgEnvironment()).andReturn(resultMock).anyTimes();
        EasyMock.replay(emMock);

        EnvironmentServiceBean bean = new EnvironmentServiceBean(emMock);

        EnvironmentInfo result = bean.getEnvironmentInfo();
        Assert.assertNotNull(result.getIdentifier());
        Assert.assertNotNull(result.getMiddlewareVersion());
    }
    
}
